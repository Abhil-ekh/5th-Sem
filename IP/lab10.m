pkg load image
img = imread('ava.jpg');

if ndims(img) == 3
    img = rgb2gray(img);
end

img = im2double(img);

mean = 0;
variance = 0.01;
noisy_img = imnoise(img, 'gaussian', mean, variance);

figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Gaussian Noisy Image');