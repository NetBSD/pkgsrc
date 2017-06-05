# $NetBSD: Makefile,v 1.6 2017/06/05 14:25:31 ryoon Exp $

DISTNAME=	Session-Storage-Secure-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Session-Storage-Secure/
COMMENT=	Encrypted, expiring, compressed, serialized session data with integrity
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Session/Storage/Secure/.packlist

DEPENDS+=	p5-Crypt-CBC>=0:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=	p5-Crypt-URandom-[0-9]*:../../security/p5-Crypt-URandom
# Digest::SHA is in Core ...
# MIME::Base64 : "3.12" - since 5.13.8 in Core
DEPENDS+=	p5-Math-Random-ISAAC-XS-[0-9]*:../../math/p5-Math-Random-ISAAC-XS
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-MooX-Types-MooseLike>=0.16:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-Sereal-Decoder-[0-9]*:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder-[0-9]*:../../converters/p5-Sereal-Encoder
DEPENDS+=	p5-String-Compare-ConstantTime-[0-9]*:../../textproc/p5-String-Compare-ConstantTime
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Number-Tolerant-[0-9]*:../../math/p5-Number-Tolerant

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
