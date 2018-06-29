#!/usr/bin/env python
# encoding: utf-8

import random
import string
import signal
import sys
import os
import time
from hashlib import sha256
from urlparse import parse_qsl

os.chdir(os.path.dirname(os.path.abspath(__file__)))
signkey = ''.join([random.choice(string.letters+string.digits) for _ in xrange(random.randint(8,32))])
items = [('Intel Core i9-7900X', 999), ('Intel Core i7-7820X', 599), ('Intel Core i7-7700K', 349), ('Intel Core i5-7600K', 249), ('Intel Core i3-7350K', 179), ('AMD Ryzen Threadripper 1950X', 999), ('AMD Ryzen 7 1800X', 499), ('AMD Ryzen 5 1600X', 249), ('AMD Ryzen 3 1300X', 149), ('Flag', 99999)]
money = random.randint(1000, 10000)

def list_items():
    for i,item in enumerate(items):
        print '%2d - %-30s$%d' % (i, item[0], item[1])

def order():
    n = input_int('Product ID: ')
    if n < 0 or n >= len(items):
        print 'Invalid ID!'
        return
    payment = 'product=%s&price=%d&timestamp=%d' % (items[n][0], items[n][1], time.time()*1000000)
    sign = sha256(signkey+payment).hexdigest()
    payment += '&sign=%s' % sign
    print 'Your order:\n%s\n' % payment

def pay():
    global money
    print 'Your order:'
    sys.stdout.flush()
    payment = raw_input().strip()
    sp = payment.rfind('&sign=')
    if sp == -1:
        print 'Invalid Order!'
        return
    sign = payment[sp+6:]
    try:
        sign = sign.decode('hex')
    except TypeError:
        print 'Invalid Order!'
        return

    payment = payment[:sp]
    signchk = sha256(signkey+payment).digest()
    if signchk != sign:
        print 'Invalid Order!'
        return

    for k,v in parse_qsl(payment):
        if k == 'product':
            product = v
        elif k == 'price':
            try:
                price = int(v)
            except ValueError:
                print 'Invalid Order!'
                return

    if money < price:
        print 'Go away you poor bastard!'
        return

    money -= price
    print 'Your current money: $%d' % money
    print 'You have bought %s' % product
    if product == 'Flag':
        print 'Good job! Here is your flag: %s' % open('flag').read().strip()

def input_int(prompt):
    sys.stdout.write(prompt)
    sys.stdout.flush()
    try:
        n = int(raw_input())
        return n
    except:
        return 0

def menu():
    print "CPU Shop"
    while True:
        print "Money: $%d" % money
        print "1. List Items"
        print "2. Order"
        print "3. Pay"
        print "4. Exit"
        sys.stdout.flush()
        choice = input_int("Command: ")
        {
                1: list_items,
                2: order,
                3: pay,
                4: exit,
        }.get(choice, lambda *args:1)()
        sys.stdout.flush()

if __name__ == "__main__":
    signal.alarm(60)
    menu()

