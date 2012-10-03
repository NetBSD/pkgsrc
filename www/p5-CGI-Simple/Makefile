# $NetBSD: Makefile,v 1.9 2012/10/03 21:58:36 wiz Exp $

DISTNAME=	CGI-Simple-1.113
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5cgs
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Simple/
COMMENT=	Simple totally OO CGI interface that is CGI.pm compliant
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
