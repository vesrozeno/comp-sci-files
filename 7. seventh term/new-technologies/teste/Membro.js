import React from "react";
import { Text, View } from "react-native";

export default (props) => {
  return (
    <Text style={{ fontSize: 12, fontWeight: "bold" }}>
      {props.nome} {props.sobrenome}
    </Text>
  );
};
