# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:40 seb Exp $

DISTNAME=	Catalyst-Model-File-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-File/
COMMENT=	File based storage model for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.69000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Component-InstancePerContext-[0-9]*:../../www/p5-Catalyst-Component-InstancePerContext
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Model/File/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
