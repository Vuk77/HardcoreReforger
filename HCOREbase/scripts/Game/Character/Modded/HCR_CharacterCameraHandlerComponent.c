modded class SCR_CharacterCameraHandlerComponent
{
    override int CameraSelector()
    {
        if (IsInThirdPerson() && !m_OwnerCharacter.IsInVehicle())
        {
            SetThirdPerson(false);
			
            return CharacterCameraSet.CHARACTERCAMERA_1ST;
        }
        
        if(m_OwnerCharacter.IsInVehicle())
        {
            CompartmentAccessComponent compartmentAccess = m_OwnerCharacter.GetCompartmentAccessComponent();
			IEntity vehicle = compartmentAccess.GetVehicleIn(m_OwnerCharacter);
			BaseCompartmentSlot currentCompartment = compartmentAccess.GetCompartment();
			
			if(currentCompartment && currentCompartment.GetType() == ECompartmentType.Cargo)
            {
				SetThirdPerson(false);
				
				return CharacterCameraSet.CHARACTERCAMERA_1ST_VEHICLE;
			}
        }    

        return super.CameraSelector();
    };
};