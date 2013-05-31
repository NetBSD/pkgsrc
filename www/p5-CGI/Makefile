# $NetBSD: Makefile,v 1.61 2013/05/31 12:42:35 wiz Exp $

VERS=		3.60
DISTNAME=	CGI.pm-${VERS}
PKGNAME=	p5-CGI-${VERS}
PKGREVISION=	2
SVR4_PKGNAME=	p5cgi
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI.pm/
COMMENT=	Perl5 module for writing forms-based CGI programs
LICENSE=	gnu-gpl-v2 OR artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/CGI/.packlist
REPLACE_PERL+=		examples/*.pl
REPLACE_PERL+=		examples/*.cgi

HTMLDIR=		${PREFIX}/share/doc/p5-CGI
DEPENDS+=		p5-FCGI>=0.67:../../www/p5-FCGI

post-build:
	cd ${WRKSRC}/examples && chmod +x *.cgi && perl make_links.pl

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}/examples
	cd ${WRKSRC} && ${INSTALL_DATA} *.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/examples &&					\
	${INSTALL_DATA} *.gif *.html *.txt *.xbm			\
	${DESTDIR}${HTMLDIR}/examples && ${INSTALL_SCRIPT} *.cgi 	\
	${DESTDIR}${HTMLDIR}/examples

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
