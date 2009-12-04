# $NetBSD: Makefile,v 1.1.1.1 2009/12/04 22:35:00 seb Exp $

DISTNAME=	ack-1.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ack/
COMMENT=	Grep-like text finder
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ack/.packlist

DEPENDS+=	p5-File-Next-[0-9]*:../../devel/p5-File-Next
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
BUILD_DEPENDS+=	p5-Test-Harness>=2.5:../../devel/p5-Test-Harness

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
