function CFR_friction_setModel(frictionModel)
% Turn friction on or off in all contact force blocks in a model 
% from SimMechanics Contact Force Library. Pass the name of the model
% as an argument to this function

% Copyright 2014-2015 The MathWorks, Inc.

CR_bpth=find_system(bdroot,'RegExp','on','LookUnderMasks','on','FollowLinks','on','friction_law','.*');

if(~isempty(CR_bpth))
    for i=1:length(CR_bpth)
        set_param(char(CR_bpth(i)),'friction_law',frictionModel);
    end
end    
end
