# $NetBSD: Makefile,v 1.38 2006/07/12 17:03:43 heinz Exp $
#

VERS=			3.20
DISTNAME=       	CGI.pm-${VERS}
PKGNAME=        	p5-CGI-${VERS}
SVR4_PKGNAME=		p5cgi
CATEGORIES=		www perl5
MASTER_SITES+=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://stein.cshl.org/WWW/software/CGI/
COMMENT=		Perl5 module for writing forms-based CGI programs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CGI/.packlist
HTMLDIR=		${PREFIX}/share/doc/html/p5-CGI

post-build:
	cd ${WRKSRC}/examples;						\
	for file in *.cgi *.pl; do					\
		${SED}	-e "s|^#!/.*|#!${PERL5}|g"			\
			$${file} > $${file}.tmp;			\
		${MV} -f $${file}.tmp $${file};				\
	done;								\
	${CHMOD} +x *.cgi;						\
	${PERL5} make_links.pl

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/examples
	cd ${WRKSRC}; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/examples;						\
	${INSTALL_DATA} *.gif *.html *.txt *.xbm ${HTMLDIR}/examples;	\
	${INSTALL_SCRIPT} *.cgi ${HTMLDIR}/examples

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
