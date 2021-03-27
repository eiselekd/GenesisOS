# Genesis OS
## A brief forray into OS dev

Everything is essentially implemented ver-batim from [wiki.osdev.org]

Implemented:
    - Boilerplate (GDT, IDT)


    Delete the relevant section from the .gitmodules file.
    Stage the .gitmodules changes git add .gitmodules
    Delete the relevant section from .git/config.
    Run git rm --cached path_to_submodule (no trailing slash).
    Run rm -rf .git/modules/path_to_submodule (no trailing slash).
    Commit git commit -m "Removed submodule "
    Delete the now untracked submodule files rm -rf path_to_submodule
