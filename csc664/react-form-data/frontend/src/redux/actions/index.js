export const setImage = (image) => {
    return {
      type: 'SET_IMAGE',
      image: image
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
