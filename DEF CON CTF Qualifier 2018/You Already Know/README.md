# You already know

If you use a proxy like ZAP or burp all the time (or have opened network tab in dev tools), you would have noticed immediately that the flag really is in the response, but it's commented out.

Raw response:
```json
{"success": true, "message": "Stop overthinking it, you already know the answer here.\n\n[comment]: <> (OOO{Sometimes, the answer is just staring you in the face. We have all been there})\n\nYou already have the flag.\n\n**Seriously**, _if you can read this_, then you have the flag.\n\nSubmit it!\n"}
```

Flag: `OOO{Sometimes, the answer is just staring you in the face. We have all been there}`