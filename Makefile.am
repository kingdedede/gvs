include Makefile.tests
include data/Makefile.include
include gvs/Makefile.include
include tests/Makefile.include

SUBDIRS = . doc po

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc --enable-introspection --enable-silent-rules

gvsdocdir = ${datadir}/doc/gvs-@VERSION@
gvsdoc_DATA =
gvsdoc_DATA += README
gvsdoc_DATA += COPYING
gvsdoc_DATA += NEWS

EXTRA_DIST += $(gvsdoc_DATA)

dist-hook:
	@if test -d "$(srcdir)/.git"; then                              \
          (cd "$(srcdir)" &&                                            \
           $(top_srcdir)/missing --run git log --stat ) > ChangeLog.tmp \
           && mv -f ChangeLog.tmp $(top_distdir)/ChangeLog              \
           || (rm -f ChangeLog.tmp;                                     \
               echo Failed to generate ChangeLog >&2);                  \
	else                                                            \
	  echo A git checkout is required to generate a ChangeLog >&2;  \
	fi

uninstall-local:
	-rm -r $(gvsdocdir)
