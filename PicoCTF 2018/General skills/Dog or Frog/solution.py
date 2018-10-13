#!/usr/bin/env python2
import keras
import numpy as np
from PIL import Image
from imagehash import phash
from cleverhans.attacks import FastGradientMethod,BasicIterativeMethod,MadryEtAl
import tensorflow as tf
from cleverhans.model import Model
IMAGE_DIMS = (224, 224)
TREE_FROG_IDX = 31
TREE_FROG_STR = "tree_frog"
sess = tf.Session()
num_labels = 1000
keras.backend.set_session(sess)
def hash_hamming_distance(h1, h2):
	s1 = str(h1)
	s2 = str(h2)
	return sum(map(lambda x: 0 if x[0] == x[1] else 1, zip(s1, s2)))
def is_similar_img(path1, path2):
	image1 = Image.open(path1)
	image2 = Image.open(path2)
	dist = hash_hamming_distance(phash(image1), phash(image2))
	print("Distance %d"%dist)
	return dist <= 1
def prepare_image(image, target=IMAGE_DIMS):
	# if the image mode is not RGB, convert it
	if image.mode != "RGB":
		image = image.convert("RGB")
	# resize the input image and preprocess it
	image = image.resize(target)
	image = keras.preprocessing.image.img_to_array(image)
	image = np.expand_dims(image, axis=0)
	image = keras.applications.mobilenet.preprocess_input(image)
	# return the processed image
	return image
model = keras.models.load_model("./model.h5")
#model.summary()
src = Image.open("./trixi.png").resize(IMAGE_DIMS)
src = prepare_image(src)
score = model.predict(src)
print(score[0][TREE_FROG_IDX])
print(np.argmax(score))
attack = MadryEtAl(model,sess=sess)
attack_params = {'eps': 0.2,'nb_iter':10,'eps_iter':0.2,'y_target':np.expand_dims(np.eye(num_labels)[TREE_FROG_IDX],axis=0)}
adv_x = attack.generate_np(src, **attack_params)
adversarial = adv_x.reshape((224,224,3))
img = keras.preprocessing.image.array_to_img(adversarial)
score = model.predict(adv_x)
print(score[0][TREE_FROG_IDX])
print(np.argmax(score))
img.save("./solution.png")
assert is_similar_img("./trixi.png", "./solution.png")