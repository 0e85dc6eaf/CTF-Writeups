from keras.applications.mobilenet import preprocess_input
from keras.models import load_model
from keras.preprocessing.image import img_to_array, array_to_img
from PIL import Image
from imagehash import phash


IMAGE_DIMS = (224, 224)
TREE_FROG_IDX = 31
TREE_FROG_STR = "tree_frog"


# I'm pretty sure I borrowed this function from somewhere, but cannot remember
# the source to cite them properly.
def hash_hamming_distance(h1, h2):
    s1 = str(h1)
    s2 = str(h2)
    return sum(map(lambda x: 0 if x[0] == x[1] else 1, zip(s1, s2)))


def is_similar_img(path1, path2):
    image1 = Image.open(path1)
    image2 = Image.open(path2)

    dist = hash_hamming_distance(phash(image1), phash(image2))
    return dist <= 1


def prepare_image(image, target=IMAGE_DIMS):
    # if the image mode is not RGB, convert it
    if image.mode != "RGB":
        image = image.convert("RGB")

    # resize the input image and preprocess it
    image = image.resize(target)
    image = img_to_array(image)
    image = np.expand_dims(image, axis=0)
    image = preprocess_input(image)
    # return the processed image
    return image


def create_img(img_path, img_res_path, model_path, target_str, target_idx, des_conf=0.95):
    test = Image.open(img_path).resize(IMAGE_DIMS)
    test = prepare_image(test)
    model = load_model(model_path)

    # TODO: YOUR SOLUTION HERE


    test = test.reshape((224,224,3))
    img = array_to_img(test)
    img.save(img_res_path)


if __name__ == "__main__":
    create_img("./trixi.png", "./trixi_frog.png", "./model.h5", TREE_FROG_STR, TREE_FROG_IDX)
    assert is_similar_img("./trixi.png", "./trixi_frog.png")
