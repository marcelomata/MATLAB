% *************************** %
% 4. Ground Interaction Model %
% *************************** %

% ----------------------
% 4.1 Vertical component
% ----------------------

% stiffness of vertical ground interaction
k_gy = m*g/0.01; %[N/m]

% max relaxation speed of vertical ground interaction
v_gy_max = 0.03; %[m/s]



% ------------------------
% 4.2 Horizontal component
% ------------------------

% sliding friction coefficient
mu_slide = 0.8;

% sliding to stiction transition velocity limit
vLimit = 0.01; %[m/s]

% stiffness of horizontal ground stiction
k_gx = (2*(m_F+m_S+m_T)+m_HAT)*g/0.1; %[N/m] 0.01

% max relaxation speed of horizontal ground stiction
v_gx_max = 0.03; %[m/s] 0.03

% stiction to sliding transition coefficient
mu_stick = 0.9;


