import React from "react";
import {
  Text,
  TouchableHighlight,
  StyleSheet,
  DImensions,
  TouchableOpacity,
  Dimensions,
} from "react-native";

export default (props) => {
  return (
    <TouchableHighlight onPress={props.onClick}>
      <Text style={style.botao}>{props.label}</Text>
    </TouchableHighlight>
  );
};

const style = StyleSheet.create({
  botao: {
    fontSize: 40,
    color: "#fff",
    height: Dimensions.get("window").height / 10,
    width: Dimensions.get("window").width / 2,
    padding: 5,
    backgroundColor: "red",
    textAlign: "center",
    borderWidth: 5,
    borderColor: "#000",
    // borderRadius: '20px',
  },
});
