## Assignment 9

>

    Name : Ravish Ranjan
    Roll no. : 45
    Course : MCA
    Subject : Scientific writing and computational analysis tools

### Question 1: 2D Plotting

1. Generate y1 = sin(x) and y2 = cos(x) for x = 0:0.01:2\*pi.
2. Plot both using plot() with different colors, markers, and line styles.
3. Add title(), xlabel(), ylabel(), legend().
4. Create a 2×2 subplot with y1, y2, y1.\*y2, leaving one blank.
5. Plot bar graph, pie chart, and histogram using bar(), pie(), histogram(), with custom colors and labels.

```m
x = 0:0.01:2*pi;
y1 = sin(x);
y2 = cos(x);

%% y1,y2 on same graph
figure;
plot(x, y1, 'r-o', 'MarkerIndices', 1:50:length(x), 'DisplayName', 'sin(x)');
hold on;
plot(x, y2, 'b--s', 'MarkerIndices', 1:50:length(x), 'DisplayName', 'cos(x)');
hold off;

title('Sin and Cos Functions');
xlabel('x (radians)');
ylabel('Amplitude');
legend('show');
grid on;

%% y1,y2,y1*y2 on subplots
figure;
subplot(2,2,1);
plot(x, y1, 'r-');
title('sin(x)'); xlabel('x'); ylabel('y'); grid on;

subplot(2,2,2);
plot(x, y2, 'b--');
title('cos(x)'); xlabel('x'); ylabel('y'); grid on;

subplot(2,2,3);
plot(x, y1.*y2, 'm-.');
title('sin(x) * cos(x)'); xlabel('x'); ylabel('y'); grid on;

%% bar graph
figure;
categories = {'Mon','Tue','Wed','Thu','Fri'};
values = [3, 7, 5, 9, 4];
b = bar(values, 'FaceColor', 'flat');
b.CData = [1 0 0; 0 1 0; 0 0 1; 1 1 0; 0 1 1];
set(gca, 'XTickLabel', categories);
title('Weekly Data'); xlabel('Day'); ylabel('Value');

%% Pie Chart
figure;
pie_data = [30, 20, 25, 25];
labels = {'Group A', 'Group B', 'Group C', 'Group D'};
pie(pie_data, labels);
title('Pie Chart Distribution');
colormap(gca, 'cool');

%% Histogram
figure;
data = randn(1, 1000); % 1000 random normal values
histogram(data, 30, 'FaceColor', [0.2 0.6 0.8], 'EdgeColor', 'black');
title('Histogram of Random Data');
xlabel('Value'); ylabel('Frequency');

```

![alt text](image.png)
![alt text](image-1.png)
![alt text](image-2.png)
![alt text](image-3.png)
![alt text](image-4.png)

### Question 2: 3D Plotting

1. Create X,Y using meshgrid(-2:0.1:2) and compute Z = X.^2 - Y.^2.
2. Plot 3D surface and mesh using surf(), mesh(), and contour().
3. Apply colormap() and colorbar().
4. Create a 3D line plot: x=cos(t), y=sin(t), z=t for t=0:0.1:10 using plot3(), customizing color and style.
5. Add titles, labels, and legends.

```m
[X, Y] = meshgrid(-2:0.1:2);
Z = X.^2 - Y.^2;

%% Surf Plot
figure;
surf(X, Y, Z);
colormap('jet');
colorbar;
title('3D Surface: Z = X^2 - Y^2');
xlabel('X'); ylabel('Y'); zlabel('Z');
shading interp;

%% Mesh Plot
figure;
mesh(X, Y, Z);
colormap('parula');
colorbar;
title('3D Mesh: Z = X^2 - Y^2');
xlabel('X'); ylabel('Y'); zlabel('Z');

%% Contour Plot
figure;
contour(X, Y, Z, 20);
colorbar;
title('Contour Plot: Z = X^2 - Y^2');
xlabel('X'); ylabel('Y');

%% Line plots
t = 0:0.1:10;
x = cos(t);
y = sin(t);
z = t;

figure;
plot3(x, y, z, 'r-', 'LineWidth', 2);
title('3D Helix: x=cos(t), y=sin(t), z=t');
xlabel('cos(t)'); ylabel('sin(t)'); zlabel('t');
legend('Helix path');
grid on;
view(45, 30); % set viewing angle (azimuth, elevation)
```

![alt text](image-5.png)
![alt text](image-6.png)
![alt text](image-7.png)
![alt text](image-8.png)
