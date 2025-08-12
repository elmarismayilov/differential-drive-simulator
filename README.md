Differential Drive Simulator
A simple C++ program simulating a 2D differential drive robot’s position and orientation.
How to use:
  Input axle length.
  Enter left and right wheel speeds repeatedly.
  See updated (x, y, θ) pose printed each step.
  
Key equations:
  v = (v_r + v_l) / 2
  ω = (v_r - v_l) / L
  Pose update with time delta and trigonometry.
  
No external dependencies except standard C++ libraries.
