# $NetBSD: Makefile,v 1.8 2000/10/15 02:17:16 jlam Exp $
#

DISTNAME=       	CGI.pm-2.74
PKGNAME=        	p5-CGI-2.74
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/} \
			http://stein.cshl.org/WWW/software/CGI/

MAINTAINER=		christos@netbsd.org
HOMEPAGE=		http://stein.cshl.org/WWW/software/CGI/

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

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	@cd ${WRKSRC}/examples; ${PERL5} make_links.pl

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/examples
	cd ${WRKSRC}; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.cgi *.gif *.html *.txt *.xbm \
		${HTMLDIR}/examples

.include "../../mk/bsd.pkg.mk"
