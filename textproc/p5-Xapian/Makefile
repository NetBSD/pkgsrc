# $NetBSD: Makefile,v 1.1 2017/07/10 17:34:04 schmonz Exp $

PKGNAME=		p5-${PKGNAME_MODULE:S/^x/X/}
COMMENT=		Perl bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/perl/

USE_TOOLS+=		perl

CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL_ARCH=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ENV+=		PERL_LIB=${PERL5_INSTALLVENDORLIB:Q}

REPLACE_PERL=		perl/docs/examples/*.pl

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/perl/examples/*.pl

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/dirs.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
