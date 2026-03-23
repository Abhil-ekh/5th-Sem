pkg load image;   % Load image package

% Read image
img = imread('download.jfif');

% Convert to grayscale if needed
if ndims(img) == 3
  gray = rgb2gray(img);
else
  gray = img;
end

% Apply Sobel edge detection
edges = edge(gray, 'sobel');

% Display results
figure;

subplot(1,2,1);
imshow(gray);
title('Grayscale Image');

subplot(1,2,2);
imshow(edges);
title('Sobel Edge Detection');