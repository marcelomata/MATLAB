%% Fixed Parameters

% Leg Linkage Geometry
leg_joint_radius = 3e-3; % Effective radius for friction calculation
l1 = 100e-3;
l2 = 200e-3;
safety_limit = 10e-3;

% Encoder Zeroing Offsets
enc_zero_IA = -1.25*pi;
enc_zero_IB = -0.25*pi;
enc_zero_IIA = 1.25*pi;
enc_zero_IIB = 1.25*pi;
enc_zero_IIIA = 0.5*pi;
enc_zero_IIIB = 1.5*pi;
enc_zero_IVA = -0.25*pi;
enc_zero_IVB = 0.5*pi;
enc_zero_tail = 0;

% Foot Contact Model
foot_contact_radius = 7.5e-3;
ground_frame_depth = 0.5;
ground_length = 100;
ground_width = 10;

% BLDC Motor Model
motor_kt = 0.0707;
motor_kv = 0.0707;
motor_r = 0.14;
motor_torque_sat = 11.5;
motor_timeconst = 5e-4;


% Experiment Initial Conditions
init_x = 0;
init_y = -ground_length/2 + 2;
init_z = ground_frame_depth/2+l1+l2+0.08;
init_rot_xzx = [0 180 90]; % [deg]


%% Tunable Parameters

% Leg Linkage Friction MAYBE
leg_joint_vel_thresh = 1e-1;
leg_joint_mu_k = 0.1;
leg_joint_mu_s = 0.2;
leg_joint_fric_bw = 100;

% Foot Contact Model MAYBE
foot_contact_stiffness = 1e4;
foot_contact_damping = 1e3;
foot_contact_mu_k = 0.7;
foot_contact_mu_s = 1;
foot_contact_vel_thresh = 1e-2;

% Path Controllers NEED TUNING
angular_ctrl_p=100;
angular_ctrl_i=1;
angular_ctrl_d=1;
radial_ctrl_p=80;
radial_ctrl_i=1;
radial_ctrl_d=1;

% Initial Motor Configuration
init_theta_IA = -pi/4;
init_thetaDot_IA = 0;

init_theta_IB = pi/4;
init_thetaDot_IB = 0;

init_theta_IIA = -pi/4;
init_thetaDot_IIA = 0;

init_theta_IIB = pi/4;
init_thetaDot_IIB = 0;

init_theta_IIIA = -pi/4;
init_thetaDot_IIIA = 0;

init_theta_IIIB = pi/4;
init_thetaDot_IIIB = 0;

init_theta_IVA = -pi/4;
init_thetaDot_IVA = 0;

init_theta_IVB = pi/4;
init_thetaDot_IVB = 0;

init_theta_tail = 0;
init_thetaDot_tail = 0;

init_toe_joint_r = pi/2;
init_toe_joint_l = -pi/2;

%% Experiment Initial Setup

% Parameters to be sweeped
period = 0.33;
fore_lag = 0.45;
lr_sync = 0;

% Constant stuff
phi_0 = 0.5*asin(l1/l2);
r_0 = l2;
r_x = 0.5*l1;
r_y = 0.3*l1;

%% Model data

minitaur_model_data;
