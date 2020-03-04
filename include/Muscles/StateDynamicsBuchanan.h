#ifndef BIORBD_MUSCLES_STATE_ACTUAL_BUCHANAN_H
#define BIORBD_MUSCLES_STATE_ACTUAL_BUCHANAN_H

#include "biorbdConfig.h"
#include "Muscles/StateDynamics.h"

namespace biorbd {
namespace muscles {
///
/// \brief Time derivative of activation as described by Buchanan (https://www.sciencedirect.com/science/article/pii/S0021929003001520)
///
class BIORBD_API StateDynamicsBuchanan : public biorbd::muscles::StateDynamics
{
public:
    ///
    /// \brief Construct state dynamics
    /// \param neuralCommand The muscle neural command
    /// \param excitation The muscle excitation
    ///
    StateDynamicsBuchanan(
            biorbd::utils::Scalar neuralCommand = 0,
            biorbd::utils::Scalar excitation = 0);

    ///
    /// \brief Construct a state dynamics Buchanan from another state dynamics Buchanan
    /// \param other The other state dynamics Buchanan
    ///
    StateDynamicsBuchanan(
            const biorbd::muscles::StateDynamicsBuchanan& other);

    ///
    /// \brief Destroy class properly
    ///
    ~StateDynamicsBuchanan();

    ///
    /// \brief Deep copy of state dynamics Buchanan
    /// \return A deep copy of state dynamics Buchanan
    ///
    biorbd::muscles::StateDynamicsBuchanan DeepCopy() const;

    ///
    /// \brief Deep copy of state dynamics Buchanan into another state dynamics Buchanan
    /// \param other The state dynamics Buchanan to copy
    ///
    void DeepCopy(
            const biorbd::muscles::StateDynamicsBuchanan& other);

    ///
    /// \brief Compute and return the excitation velocity 
    /// \param characteristics The muscle characteristics
    /// \param alreadyNormalized If already normalized
    /// \return The excitation time derivative
    ///
    virtual biorbd::utils::Scalar timeDerivativeExcitation(
            const Characteristics &characteristics,
            bool alreadyNormalized);

    ///
    /// \brief Set the muscle excitation
    /// \param val Value of the muscle excitation
    /// \param turnOffWarnings If the warnings should be OFF or ON.
    ///
    virtual void setExcitation(
            biorbd::utils::Scalar val,
            bool turnOffWarnings = false);

    ///
    /// \brief Set the neural command
    /// \param val Value of the neural command
    ///
    virtual void setNeuralCommand(
            biorbd::utils::Scalar val);

   ///
   /// \brief Set the shape factor
   /// \param shape_factor Value of the shape factor
   ///
    void shapeFactor(
            biorbd::utils::Scalar shape_factor);

    ///
    /// \brief Return the shape factor
    /// \return The shape factor
    ///
    biorbd::utils::Scalar shapeFactor() const;

    ///
    /// \brief Set the muscle activation
    /// \param notUsed the activation is computed from the neuralCommand and excitation
    ///
    void setActivation(
            biorbd::utils::Scalar notUsed,
            bool turnOffWarnings = false);

protected:
    ///
    /// \brief Set type to Buchanan
    ///
    virtual void setType();

    std::shared_ptr<biorbd::utils::Scalar> m_neuralCommand; ///< The muscle neural command
    std::shared_ptr<biorbd::utils::Scalar> m_shapeFactor; ///< The shape factor (Buchanan2004, march 22nd, 2018)
    std::shared_ptr<biorbd::utils::Scalar> m_excitationDot; ///< The excitation velocity

};

}}

#endif // BIORBD_MUSCLES_STATE_ACTUAL_BUCHANAN_H
