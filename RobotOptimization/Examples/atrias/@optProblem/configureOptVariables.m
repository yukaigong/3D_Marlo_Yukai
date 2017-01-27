function [obj] = configureOptVariables(obj)            
    % configureOptVariables - register optimization variables
    %
    % Copyright 2014-2015 Texas A&M University AMBER Lab
    % Author: Ayonga Hereid <ayonga@tamu.edu>
    DOF = 16;
    DOA = 6;
    M = 5;
    NHC = 7;
    
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
            DOF,1:(domain.nNode),...
            domain.minJointAngles,...
            domain.maxJointAngles);

        % joint velocity (dq)
        domain = addVariable(domain,'dq',...
            DOF,1:(domain.nNode),...
            domain.minJointVelocities,...
            domain.maxJointVelocities);
        
        % joint acceleration (ddq)
        domain = addVariable(domain,'ddq',...
            DOF,1:(domain.nNode),...
            domain.minJointAccels,...
            domain.maxJointAccels);

        % actuator torque (u)
        domain = addVariable(domain,'u',...
            DOA,1:(domain.nNode),...
            domain.minTorques,...
            domain.maxTorques);

        % constraint force (Fe)
        domain = addVariable(domain,'Fe',...
            NHC,1:(domain.nNode),...
            domain.minConstrForces,...
            domain.maxConstrForces);

        % desired function parameters (a)
        domain = addVariable(domain,'a',...
            DOA*(M+1),1:(domain.nNode),...
            domain.minAlpha,...
            domain.maxAlpha);
        
        % desired holonomic constraints (h)
        % h(1): desired stance foot y
        % h(2): desired stance foot z
        domain = addVariable(domain,'h',...
            NHC,1:domain.nNode,...
            domain.minConstrForces,...
            domain.maxConstrForces);

        % Impact force (Fimp)
        domain = addVariable(domain,'Fimp',...
            NHC,domain.nNode,domain.minImpactForces,...
            domain.maxImpactForces);
        
        % Post-Impact q
        domain = addVariable(domain,'qend',...
            DOF,domain.nNode,...
            domain.minJointAngles,...
            domain.maxJointAngles);
        
        % Post-Impact dq
        domain = addVariable(domain,'dqend',...
            DOF,domain.nNode,...
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