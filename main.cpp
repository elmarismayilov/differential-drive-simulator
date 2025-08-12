#include <iostream>
#include <chrono>

int main()
{
    float v_r, v_l;
    using clock = std::chrono::steady_clock;
    auto last_time = clock::now();
    int L;
    std::cout << "Enter axle length: ";
    std::cin >> L;
    int step_counter = 1;
    float x_old = 0;
    float y_old = 0;
    float theta_old = 0;
    while (true)
    {
        auto current_time = clock::now();
        std::chrono::duration<double> elapsed = current_time - last_time;
        double delta_time = elapsed.count(); 
        last_time = current_time;
        std::cout << "Enter values for v_r and v_l: ";
        std::cin >> v_r >> v_l;
        float v = (v_r+v_l)/2;
        float w = (v_r-v_l)/L;
        float x_new = x_old + v * cos(theta_old) * delta_time;
        float y_new = y_old + v * sin(theta_old) * delta_time;
        float theta_new = theta_old + w * delta_time;
        std::cout << "Step " << step_counter << " > " << "x: " << x_new << " y: " << y_new << " theta: " << theta_new << " rad\n";
        x_old = x_new;
        y_old = y_new;
        theta_old = theta_new;
        step_counter++;
    }
    return 0;
}