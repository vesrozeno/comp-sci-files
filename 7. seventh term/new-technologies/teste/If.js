import React from "react";
import { Text, View } from "react-native";

export default (props) => {
  if (props.teste) {
    return props.children;
  } else {
    return false;
  }
};
