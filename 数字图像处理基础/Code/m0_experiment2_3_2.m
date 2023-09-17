% 在频率域构建高斯低通滤波器和高斯高通滤波，对1.jpg图像进行滤波，观察不同D0的滤波效果
% for 循环逐点计算构建滤波器
% 读入图片并转换为灰度图像
l1 = imread('G:\SCHOOL\100 计算机科学与技术 专选课\200 数字图像处理基础\第二次上机实验\1.jpg');
l1 = rgb2gray(l1);
l1 = im2double(l1);
l2 = imread('G:\SCHOOL\100 计算机科学与技术 专选课\200 数字图像处理基础\第二次上机实验\1.jpg');
l2 = rgb2gray(l2);
l2 = im2double(l2);

% 计算图像的尺寸和中心点
[W1,H1] = size(l1);
u1 = -W1/2:(W1/2-1);
v1 = -H1/2:(H1/2-1);


% 计算高斯滤波器并进行滤波
D01 = 5;
K1 = zeros(W1, H1); % 高斯低通滤波器
for i = 1:W1
    for j = 1:H1
        D1 = sqrt(u1(i)^2 + v1(j)^2);
        K1(i, j) = exp(-(D1^2) / (2 * D01^2));
    end
end

K2 = zeros(W1, H1); % 高斯高通滤波器
for i = 1:W1
    for j = 1:H1
        D1 = sqrt(u1(i)^2 + v1(j)^2);
        K2(i, j) = 1 - exp(-(D1^2) / (2 * D01^2));
    end
end 

J1 = fftshift(fft2(l1));
L1 = J1.*K1;
I1 = ifft2(fftshift(L1));
L2 = J1.*K2;
I2 = ifft2(fftshift(L2));

% 绘制第一个图像的滤波结果
figure(1);
subplot(3,2,1);
imshow(l1);
title('原图像');
subplot(3,2,3);
imshow(I1);
title('高斯低通滤波器 D0=5');
subplot(3,2,4);
imshow(I2);
title('高斯高通滤波器 D0=5');

% 计算第二个图像的高斯滤波结果
[W2,H2] = size(l2);
u2 = -W2/2:(W2/2-1);
v2 = -H2/2:(H2/2-1);
D2 = zeros(W2,H2);
D02 = 10;
K3 = zeros(W2,H2);
K4 = zeros(W2,H2);
for i=1:W2
    for j=1:H2
        D2(i,j) = sqrt(u2(i)^2 + v2(j)^2);
        K3(i,j) = exp(-(D2(i,j)^2)/(2*D02^2));
        K4(i,j) = 1 - exp(-(D2(i,j)^2)/(2*D02^2));
    end
end
J2 = fftshift(fft2(l2));
L3 = J2.*K3;
I3 = ifft2(fftshift(L3));
L4 = J2.*K4;
I4 = ifft2(fftshift(L4));

% 绘制第二个图像的滤波结果
subplot(3,2,5);
imshow(I3);
title('高斯低通滤波器 D0=10');
subplot(3,2,6);
imshow(I4);
title('高斯高通滤波器 D0=10');
