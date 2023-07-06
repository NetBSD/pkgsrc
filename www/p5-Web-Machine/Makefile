# $NetBSD: Makefile,v 1.3 2023/07/06 09:43:00 wiz Exp $

DISTNAME=	Web-Machine-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Web-Machine
COMMENT=	Perl port of Webmachine
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-HTTP-Headers-ActionPack-[0-9]*:../../www/p5-HTTP-Headers-ActionPack
DEPENDS+=	p5-IO-Handle-Util-[0-9]*:../../devel/p5-IO-Handle-Util
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

PERL5_PACKLIST=		auto/Web/Machine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
