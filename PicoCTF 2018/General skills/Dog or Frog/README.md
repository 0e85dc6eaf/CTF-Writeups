# Dog or Frog

> Dressing up dogs are kinda the new thing, see if you can get this lovely girl ready for her costume party. Dog Or Frog

Hints:

> This really is a ML problem, read the hints in the problem for more details..

This was one of the most difficult challenges for me. When I noticed that we have model and source code I thought of implementing genetic algorithm for it. (I don't know if it is solvable in reasonable time this way)

But then I realized solution template and read the article about adversarial images... it seemed clear to me that I need more clever attack, but I don't have any experience in ML, so I didn't know where to start.

I spent three days reading articles, watching tutorials. I also tried to use some read solutions from github, but they didn't work. I also tried to implement my own solution with [foolbox](https://github.com/bethgelab/foolbox), but I couldn't get it to work.

In the end I used [cleverhans](https://github.com/tensorflow/cleverhans). I had some problems with one-hot encoding, but eventually I found the correct way to do it.
```python
np.expand_dims(np.eye(num_labels)[TREE_FROG_IDX])
```
At least this one worked for me(I tried 6-7 different methods).

Apart from that there weren't any difficulties with implementation. All magic happened in the library, I just got final results.
[solution](solution.py)

When I was doing this writeup I realized that my script produces different results with every run, so you may need to run it a few times. When I ran it first time I got 97% frog with 0 bits difference, but second time it was only 0.0001%. Current version [solution.png](solution.png) has 99% probability and 0 bits difference.

Flag is `picoCTF{n0w_th4t3_4_g00d_girl_faa671cf}`.