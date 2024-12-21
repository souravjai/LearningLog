import react from "react";
import data from "./assets/data.json";
import Accordian from "./component/Accordian";
import "./App.css";
function App() {
	return (
		<div>
			{data.map((user) => (
				<Accordian key={user.id} {...user} />
			))}
		</div>
	);
}

export default App;
