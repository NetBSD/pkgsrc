# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:26:03 jlam Exp $

DISTNAME=	ramaze-0.3.9.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework 

DEPENDS+=	rake>=0.7.3:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.2.0:../../www/ruby-rack

# The ramaze gem installs the RDoc files under ${GEM_LIBDIR} instead of
# ${GEM_DOCDIR}, so we need to generate the dynamic PLIST entries for
# those files.
#
GENERATE_PLIST+= \
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${DESTDIR}${PREFIX} && \
          ${FIND} ${GEM_LIBDIR:S|${PREFIX}/||}/rdoc \! -type d -print | \
                ${SORT} && \
          ${FIND} ${GEM_LIBDIR:S|${PREFIX}/||}/rdoc -type d -print | \
                ${SORT} -r | ${SED} -e "s,^,@dirrm ," && \
	  ${ECHO} "@dirrm "${GEM_LIBDIR:S|${PREFIX}/||:Q} );

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
