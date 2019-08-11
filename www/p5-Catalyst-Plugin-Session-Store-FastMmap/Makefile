# $NetBSD: Makefile,v 1.25 2019/08/11 13:24:33 wiz Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-FastMmap-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Session-Store-FastMmap
COMMENT=	FastMmap session storage backend
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-Cache-FastMmap>=1.29:../../devel/p5-Cache-FastMmap
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.27:../../www/p5-Catalyst-Plugin-Session
#DEPENDS+=       {perl>=5.10,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
#DEPENDS+=	{perl>=5.10,p5-MRO-Compat-[0-9]*}:../../devel/p5-MRO-Compat
DEPENDS+=       p5-Path-Class>=0:../../devel/p5-Path-Class
#DEPENDS+=       {perl>=5.10,p5-PathTools-[0-9]*}:../../devel/p5-PathTools
DEPENDS+=       p5-MooseX-Emulate-Class-Accessor-Fast-[0-9]*:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=       p5-Catalyst-Runtime>=5.9:../../www/p5-Catalyst-Runtime

# Missed in package META.yml
DEPENDS+=       p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/FastMmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
