function [obj] = configureOptVariables(obj)            
    % configureOptVariables - register optimization variables
    %
    % Copyright 2014-2015 Texas A&M University AMBER Lab
    % Author: Ayonga Hereid <ayonga@tamu.edu>
    
    startingIndex = 0;
    for i=1:obj.nDomain
        
        domain = obj.domains{i};
        %% register optimization variables        
        
        % time duration (t)
        nodeList = 1:1:domain.nNode;
        domain = addVariable(domain,'t',...
            1,nodeList,domain.minTimeInterval,...
            domain.maxTimeInterval);
          
        % joint displacement (q)
        domain = addVariable(domain,'q',...
            22,1:(domain.nNode),...
            domain.minJointAngles,...
            domain.maxJointAngles);

        % joint velocity (dq)
        domain = addVariable(domain,'dq',...
            22,1:(domain.nNode),...
            domain.minJointVelocities,...
            domain.maxJointVelocities);
        
        % joint acceleration (ddq)
        domain = addVariable(domain,'ddq',...
            22,1:(domain.nNode),...
            domain.minJointAccels,...
            domain.maxJointAccels);

        % actuator torque (u)
        domain = addVariable(domain,'u',...
            10,1:(domain.nNode),...
            domain.minTorques,...
            domain.maxTorques);

        % constraint force (Fe)
        domain = addVariable(domain,'Fe',...
            12,1:(domain.nNode),...
            domain.minConstrForces,...
            domain.maxConstrForces);

        % desired function parameters (a)
        domain = addVariable(domain,'a',...
            60,1:(domain.nNode),...
            domain.minAlpha,...
            domain.maxAlpha);
        
        % desired holonomic constraints (h)
        % h(1): desired stance foot y
        % h(2): desired stance foot z
        domain = addVariable(domain,'h',...
            12,1:domain.nNode,...
            domain.minConstrForces,...
            domain.maxConstrForces);

        % Impact force (Fimp)
        domain = addVariable(domain,'Fimp',...
            12,domain.nNode,domain.minImpactForces,...
            domain.maxImpactForces);
        
        % Post-Impact q
        domain = addVariable(domain,'qend',...
            22,domain.nNode,...
            domain.minJointAngles,...
            domain.maxJointAngles);
        
        % Post-Impact dq
        domain = addVariable(domain,'dqend',...
            22,domain.nNode,...
            domain.minJointVelocities,...
            domain.maxJointVelocities);
        
        % generate variables indices
        domain = genVarIndices(domain,startingIndex);

        % update starting index of next domain
        startingIndex = startingIndex + domain.nOptVars;
        
        obj.domains{i} = domain;
    end

    obj.nOptVar = startingIndex;

end