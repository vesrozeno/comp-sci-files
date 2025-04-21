import React from "react";
import { Text, View } from "react-native";

export default (props) => {
  return (
    <>
      <Text style={{ fontSize: 18, fontWeight: "bold", textAlign: "center" }}>
        Membros:
      </Text>
      {props.children}
    </>
  );
};
