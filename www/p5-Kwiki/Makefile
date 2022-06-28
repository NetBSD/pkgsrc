# $NetBSD: Makefile,v 1.29 2022/06/28 11:37:32 wiz Exp $

DISTNAME=	Kwiki-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Extensible, modular, Perl-based Wiki

DEPENDS+=	p5-Spoon>=0.22:../../devel/p5-Spoon

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

PERL5_PACKLIST=		auto/Kwiki/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
