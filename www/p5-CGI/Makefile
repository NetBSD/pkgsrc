# $NetBSD: Makefile,v 1.44 2008/08/24 14:00:59 tonnerre Exp $

VERS=		3.40
DISTNAME=	CGI.pm-${VERS}
PKGNAME=	p5-CGI-${VERS}
SVR4_PKGNAME=	p5cgi
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI.pm/
COMMENT=	Perl5 module for writing forms-based CGI programs

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
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/examples
	cd ${WRKSRC} && ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/examples &&					\
	${INSTALL_DATA} *.gif *.html *.txt *.xbm ${HTMLDIR}/examples &&	\
	${INSTALL_SCRIPT} *.cgi ${HTMLDIR}/examples

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
