# $NetBSD: Makefile,v 1.7 2000/09/15 14:50:58 jlam Exp $
#

DISTNAME=       	CGI.pm-2.72
PKGNAME=        	p5-CGI-2.72
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		christos@netbsd.org

# Some perl packages install their own versions of this module.
# Can't simply define USE_PERL5.
DEPENDS+=		perl-{5.0*,5.6.0nb2,base-5.[6-9]*}:../../lang/perl5-base

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/.packlist
HTMLDIR=		${PREFIX}/share/doc/html/p5-CGI

post-extract:
	@cd ${WRKSRC}/examples; for file in *.cgi *.html *.pl; do \
		${MV} -f $${file} $${file}.tmp; \
		${SED} -e "s,/usr/local/bin/perl,${PERL5},g" \
			< $${file}.tmp > $${file}; \
		${RM} -f $${file}.tmp; \
	done

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	@cd ${WRKSRC}/examples; ${PERL5} make_links.pl

pre-install:
	@${RM} -rf ${WRKSRC}/examples/WORLD_WRITABLE

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/cgi*.html ${HTMLDIR}
	${CP} -R ${WRKSRC}/examples ${HTMLDIR}/examples
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HTMLDIR}/examples

.include "../../mk/bsd.pkg.mk"
