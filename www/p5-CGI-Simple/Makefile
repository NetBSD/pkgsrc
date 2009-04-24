# $NetBSD: Makefile,v 1.4 2009/04/24 06:50:42 sno Exp $

DISTNAME=	CGI-Simple-1.109
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cgs
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Simple/
COMMENT=	Simple totally OO CGI interface that is CGI.pm compliant

DEPENDS+=       p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
