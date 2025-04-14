// ...existing code...

void OptionsGameplayMenu()
{
	// ...existing code...
	vecOptions.push_back(_("Smooth Movement"));
	vecOptionsSettings.push_back(GetSmoothMovement() ? OptionEntryFlags::On : OptionEntryFlags::Off);
	// ...existing code...
}

void OptionsGameplayMenuSelect(int value)
{
	// ...existing code...
	if (vecOptions[value] == "Smooth Movement") {
		SetSmoothMovement(!GetSmoothMovement());
		vecOptionsSettings[value] = GetSmoothMovement() ? OptionEntryFlags::On : OptionEntryFlags::Off;
	}
	// ...existing code...
}

// ...existing code...