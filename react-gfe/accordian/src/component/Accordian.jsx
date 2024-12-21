import react, { useState } from "react";

function Accordian({ label, content }) {
	const [isCollapsed, setIsCollapsed] = useState(true);
	return (
		<div className='accordian' aria-expanded={!isCollapsed}>
			<div
				onClick={() => setIsCollapsed((prev) => !prev)}
				className='accordian__ele'>
				<span className='accordian__label'>{label}</span>
				<span className='arrow'>➡️</span>
			</div>
			{!isCollapsed && <p className='accordian__content'>{content}</p>}
		</div>
	);
}

export default Accordian;
