# $NetBSD: Makefile,v 1.9 2006/03/14 16:04:46 jlam Exp $

DISTNAME=      	Kwiki-0.38
PKGNAME=       	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Extensible, modular, Perl-based Wiki

DEPENDS+=	p5-Spoon>=0.21nb1:../../devel/p5-Spoon

PERL5_PACKLIST=		auto/Kwiki/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
