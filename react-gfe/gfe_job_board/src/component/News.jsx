import React from "react";

export default function News(props) {
	return (
		<div className='news'>
			{props.hasOwnProperty("url") ? (
				<a href={props.url} target='_blank'>
					{props.title}
				</a>
			) : (
				<strong>{props.title}</strong>
			)}

			<div className='news__footer'>
				<span>
					By: {props.by} . {new Date(props.time).toLocaleTimeString()}
				</span>
			</div>
		</div>
	);
}
