# $NetBSD: Makefile,v 1.65 2014/05/31 22:22:12 wiz Exp $

VERS=		4.01
DISTNAME=	CGI.pm-${VERS}
PKGNAME=	p5-CGI-${VERS}
PKGREVISION=	1
SVR4_PKGNAME=	p5cgi
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI.pm/
COMMENT=	Perl5 module for writing forms-based CGI programs
LICENSE=	gnu-gpl-v2 OR artistic-2.0

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/CGI/.packlist
REPLACE_PERL+=		examples/*.pl
REPLACE_PERL+=		examples/*.cgi

HTMLDIR=		${PREFIX}/share/doc/p5-CGI
INSTALLATION_DIRS=	${HTMLDIR}/examples

post-build:
	cd ${WRKSRC}/examples && chmod +x *.cgi && perl make_links.pl

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.gif *.html *.txt *.xbm \
		${DESTDIR}${HTMLDIR}/examples && \
	${INSTALL_SCRIPT} *.cgi ${DESTDIR}${HTMLDIR}/examples

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
