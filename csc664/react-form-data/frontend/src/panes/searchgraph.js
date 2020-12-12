import React, { Component } from 'react';
import * as d3 from 'd3';

export default class MakeGraph extends Component {

    constructor(props) {
      super(props);
      this.myRef = React.createRef();
    }

    refreshGraph = () => {
      d3.selectAll("svg").remove();
    }

    makeGraph = () => {
      const nodes = this.props.nodelist.map((d) => Object.assign({}, d));
      const links = this.props.linklist.map((d) => Object.assign({}, d));

      console.log(links);
      console.log(nodes);

      const height = 500;
      const width = 500;

      const simulation = d3.forceSimulation(nodes)
          .force("link", d3.forceLink(links).id(d => d.id).distance(150))
          .force("charge", d3.forceManyBody())
          .force("center", d3.forceCenter(width / 2, height / 2));

      const svg = d3.select(this.myRef.current)
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height]);

      const link = svg.append("g")
                      .attr("stroke", "#999")
                      .attr("stroke-opacity", 0.6)
                      .selectAll("line")
                      .data(links)
                      .join("line")
                      .attr("stroke-width", d => Math.sqrt(d.value));

      const node = svg.append("g")
                      .attr("stroke", "#fff")
                      .attr("stroke-width", 1.5)
                      .selectAll("image")
                      .data(nodes)
                      .join("image")
                      .attr("alt","test")
                      .attr("xlink:href", d => d.image)
                      .attr("width", 60)
                      .attr("height", 60);

      node.append("title")
          .text(d => d.image);

      simulation.on("tick", () => {
        link
            .attr("x1", d => d.source.x )
            .attr("y1", d => d.source.y )
            .attr("x2", d => d.target.x )
            .attr("y2", d => d.target.y );

        node
            .attr("x", d => d.x - 30)
            .attr("y", d => d.y - 30);
      });
    }


    componentDidMount() {

      this.makeGraph();
    }

    componentDidUpdate(prevProps, prevState) {
      if (prevProps !== this.props) {
        this.refreshGraph();
        this.makeGraph();
      }
    }

      render() {
        return (
          <div ref={this.myRef}> </div>
        );}

}
