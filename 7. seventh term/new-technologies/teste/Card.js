import React from "react";
import { Text, View } from "react-native";

export default (props) => {
  return (
    <View style={{ borderWidth: 2, padding: 10, margin: 10, borderRadius: 16 }}>
      {props.children}
    </View>
  );
};
