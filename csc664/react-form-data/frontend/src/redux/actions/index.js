export const setImage = (image) => {
    return {
      type: 'SET_IMAGE',
      image: image.image,
      id: image.id
    }
}

export const imageModal = () => {
  return {
    type: 'IMAGE_MODAL',
  }
}

export const facetModal = () => {
  return {
    type: 'FACET_MODAL',
  }
}

export const regionModal = () => {
  return {
    type: 'REGION_MODAL',
  }
}

export const searchModal = () => {
  return {
    type: 'SEARCH_MODAL',
  }
}

export const updateScroll = () => {
  return {
    type: 'UPDATE_SCROLL',
  }
}

export const updateView = () => {
  return {
    type: 'UPDATE_VIEW',
  }
}

export const startSearch = () => {
  return {
    type: 'START_SEARCH',
  }
}

export const setRegion = (region) => {
  return {
    x: region.x,
    y: region.y,
    width: region.width,
    height: region.height,
    type: 'SET_REGION'
  }
}

export const setFacet = (facet) => {
  return {
    facet: facet,
    type: 'SET_FACET'
  }
}

export const setSearch = (search) => {
  return {
    imageID: search.imageID,
    facetID: search.facetID,
    type: 'SET_SEARCH'
  }
}
