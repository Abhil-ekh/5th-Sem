clear all; % clear all variables
close all; % close all figures
clc;        % clear command window

% import image package
pkg load image;

% read image
% Implementation of filter using Convolution
% figure;
I = imread('tt.jpg');
I = I(:,:,1);
subplot(2,2,1); imshow(I); title('Original Image');

a = [0.001 0.001 0.001;
     0.001 0.001 0.001;
     0.001 0.001 0.001];

R = conv2(a, I);

subplot(2,2,2); imshow(R); title('Filtered Image');

b = [0.0001 0.0001 0.0001;
     0.0001 0.0001 0.0001;
     0.0001 0.0001 0.0001];

R1 = conv2(b, I);

subplot(2,2,3); imshow(R1); title('Filtered Image 2');
