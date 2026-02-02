pkg load image
img = imread('snp.jpg');

if ndims(img) == 3
    img = rgb2gray(img);
end

img = im2double(img);

% imnoise(image, 'salt & pepper', density)
density = 0.05;    % 5% pixels corrupted
noisy_img = imnoise(img, 'salt & pepper', density);
figure;
subplot(1,2,1), imshow(img), title('Original Image');
subplot(1,2,2), imshow(noisy_img), title('Salt & Pepper Noisy Image');
