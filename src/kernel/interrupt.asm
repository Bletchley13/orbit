global interrupt_null
interrupt_null:
	extern interrupt_handle
	call interrupt_handle
	iret