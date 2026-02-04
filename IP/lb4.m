clear all; % clear all variables
close all; % close all figures
clc;        % clear command window

% import image package
pkg load image;

% read image
a = imread('img.jfif');

subplot(2,2,1);
imshow(a);
title 'Original Image';

b = im2double(a);

a1 = input('enter value a: ');
ga1 = input('enter value gamma: ');
s = (a1*(b.^ga1))*256;
s1 = uint8(s);

subplot(2,2,2);
imshow(s1);
title 'Image 1';

a2 = input('enter value a: ');
ga2 = input('enter value gamma: ');
sp = (a2*(b.^ga2))*256;
s2 = uint8(sp);

subplot(2,2,3);
imshow(s2);
title 'Image 2';

a3 = input('enter value a: ');
ga3 = input('enter value gamma: ');
sp2 = (a3*(b.^ga3))*256;
s3 = uint8(sp2);

subplot(2,2,4);
imshow(s3);
title 'Image 3';
