# $NetBSD: Makefile,v 1.3 2018/08/26 13:25:33 schmonz Exp $

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
