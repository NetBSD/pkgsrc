# $NetBSD: Makefile,v 1.7 2011/08/14 15:28:46 obache Exp $

DISTNAME=	DateTime-Format-Mail-0.3001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Mail/
COMMENT=	Convert between DateTime and RFC2822/822 formats

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Params-Validate>=0.67:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST= auto/DateTime/Format/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
