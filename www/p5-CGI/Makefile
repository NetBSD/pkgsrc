# $NetBSD: Makefile,v 1.68 2014/10/12 14:39:49 wiz Exp $

DISTNAME=	CGI-4.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LE/LEEJO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI.pm/
COMMENT=	Perl5 module for writing forms-based CGI programs
LICENSE=	gnu-gpl-v2 OR artistic-2.0

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

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
