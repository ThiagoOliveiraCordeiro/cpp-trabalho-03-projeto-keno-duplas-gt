#ifndef _KENO_BET_H_
#define _KENO_BET_H_


/*!
 *  Class the defines a Keno bet.
 *
 *  @author Selan R. dos Santos
 *  @file keno_bet.h
 */

#include "keno_common.h"

namespace Keno
{
    class KenoBet
    {
        public:
            //! Creates a Keno bet.
            /*! A Keno bet stores the player's picked numbers or spots, up to a limit passed as argument.
             *  Any attempt of inserting spots beyond the set limit is ignored.
             *  @param max_n_sposts_ Maximim number of spots this bet may hold.
             */
            KenoBet( ) : m_wage{0.f}
            { /* empty */ }

            //! Adds a number to the player's bet.
            /*! This method adds the number passed as argument to the player's spots
             *  only if the number is not already there.
             *  @param spot The number we wish to include in the bet.
             *  @return Returns true if number chosen is successfuly inserted; false otherwise.
             */
            bool add_spot( Keno::number_type spot );

            //! Sets the player's wage on this bet.
            /*! This method set the amount of money the player is betting.
             *  @param wage The wage.
             *  @return True if we have a wage above zero; false otherwise.
             */
            bool set_wage( Keno::cash_type wage );

            //! Resets a bet to an emtpy state.
            /*! Resets a bet object to an empty state, which means the spot list clered.
            */
            void reset( void );

            //! Recovers the player's wage on this particular bet.
            /*! Retrieves the player's wage on this bet.
             *  @return The wage value.
             */
            Keno::cash_type get_wage( void ) const;


            //! Return the amount of spots currently in the bet.
            /*! Returns to the application the current number of spots in the player's bet.
             *  @return Number of spots present in the bet.
             */
            size_t size( void ) const;

            /*! Determine how many spots from the player's match the hits passed as argument.
             * @param draw List of hits randomly chosen by the computer.
             * @return An vector with the list of hits according to the currently stored bet.
             */
            Keno::set_of_numbers_type
                find_hits( const Keno::set_of_numbers_type & draw ) const;

            //! Return the player's spots.
            /*! Return an std::vector<number_type> with the spots the player has picked so far.
             *  @return The std::vector<number_type> with the plyer's spots picked so far.
             */
            Keno::set_of_numbers_type get_spots( void ) const;

        private:

            Keno::set_of_numbers_type m_spots; //<! The player's bet, i.e.\ a set of numbers (aka spots).
            Keno::cash_type m_wage;             //<! The player's wage
        
        friend class KenoGame;
    };
}

#endif
