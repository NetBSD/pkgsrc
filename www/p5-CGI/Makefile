# $NetBSD: Makefile,v 1.83 2016/03/08 15:05:04 wiz Exp $

DISTNAME=	CGI-4.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI.pm/
COMMENT=	Perl5 module for writing forms-based CGI programs
LICENSE=	gnu-gpl-v2 OR artistic-2.0

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/CGI/.packlist
REPLACE_PERL+=		examples/*.pl
REPLACE_PERL+=		examples/*.cgi

HTMLDIR=		${PREFIX}/share/doc/p5-CGI
INSTALLATION_DIRS=	${HTMLDIR}/examples

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.gif ${DESTDIR}${HTMLDIR}/examples && \
	${INSTALL_SCRIPT} *.cgi *.pl ${DESTDIR}${HTMLDIR}/examples

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
